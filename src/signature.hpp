/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * libgit2pp
 * Copyright (C) 2013 Émilien Kia <emilien.kia@gmail.com>
 * 
 * libgit2pp is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * libgit2pp is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.";
 */

#ifndef _GIT2PP_SIGNATURE_HPP_
#define _GIT2PP_SIGNATURE_HPP_

#include <git2.h>

#include <string>


namespace git2
{

/**
 * @brief This class is used for constructing new action signatures, e.g. when creating commits.
 *
 * The underlaying data structure is owned by the object, and deleted when the object is
 * destroyed.
 *
 * The interface provided by this class is identical to Signature, with additional
 * constructors for creating new signatures.
 */
#if 0 // Removed for upgrading to 0.24.0
class SignatureBuilder
{
public:

    /**
     * Construct a new action signature.
     *
     * @param name name of the person
     * @param email email of the person
     * @param dateTime time when the action happened
	 * @param offset timezone offset in minutes for the time
     * @throws Exception
     */
    SignatureBuilder(const std::string& name, const std::string& email, time_t dateTime, int offset = 0);

    /**
     * Construct a new action signature, using the `now` datetime generated by the
     * underlaying library.
     *
     * @param name name of the person
     * @param email email of the person
     * @throws Exception
     */
    SignatureBuilder(const std::string& name, const std::string& email);

    /**
     * Construct a copy of an existing signature.
     *
     * All internal strings are also duplicated.
     *
     * @param sign signature to duplicated
     */
    SignatureBuilder(const SignatureBuilder& sign);

    /**
     * Delete an existing signature
     */
    ~SignatureBuilder();

    /**
     * Return the 'name' from this signature
     */
    std::string name() const;

    /**
     * Return the 'email' from this signature
     */
    std::string email() const;

    /**
     * Return the time stamp from this signature
     */
    time_t when() const;

    /**
     * Return the time timezone offset from this signature
     */
    int when_offset() const;

    const git_signature* data() const;

private:
    git_signature *_sign;
};
#endif // Removed for upgrading to 0.24.0


/**
 * @brief This class provides a thin wrapper around an existing signature data structure.
 *
 * An instance of this class does not own the underlaying data structure, only a reference
 * (pointer) to it.
 *
 * Use SignatureBuilder to create new signatures.
 */
class Signature
{
public:

    /**
     * Create a reference to the 'signature'; ownership of the pointer is not transferred.
     */
    explicit Signature(const git_signature *signature = 0);

    /**
     * Create another reference to the signature referenced by 'other'
     */
    Signature(const Signature& other);

    /**
     * Create a reference to the signature owned by 'other'; this allows SignatureBuilder to
     * be passed as Signature function argument.
     */
#if 0 // Removed for upgrading to 0.24.0
    Signature(const SignatureBuilder& other);
#endif // Removed for upgrading to 0.24.0

    /**
     * Destroy the reference; does not destroy the underlaying data structure,
     * because it's not owned by this reference
     */
    ~Signature();

    /**
     * Return the 'name' from this signature
     */
    std::string name() const;

    /**
     * Return the 'email' from this signature
     */
    std::string email() const;

    /**
     * Return the time stamp from this signature
     */
    time_t when() const;

    /**
     * Return the time timezone offset from this signature
     */
    int when_offset() const;

    const git_signature *data() const;

private:
    const git_signature *_sign;
};

} // namespace git2
#endif // _GIT2PP_SIGNATURE_HPP_

